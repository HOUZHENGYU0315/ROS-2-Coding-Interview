import rclpy
from rclpy.node import Node
from driver_msgs.msg import Target  # 引入自定义消息
from collections import deque

class ProcessNode(Node):
    def __init__(self):
        super().__init__('process_node')
        # 创建订阅者，使用自定义消息类型
        self.subscription = self.create_subscription(
            Target,
            'target',
            self.listener_callback,
            10)
        # 创建发布者，使用自定义消息类型
        self.publisher_ = self.create_publisher(Target, 'command', 10)
        # 创建定时器
        self.timer = self.create_timer(0.01, self.timer_callback)  # 100Hz
        self.message_window = deque(maxlen=5)
        self.counter = 0

    def listener_callback(self, msg):
        # 将接收到的消息存储到窗口中
        self.message_window.append(msg)

    def timer_callback(self):
        if not self.message_window:
            self.get_logger().warn('No messages received yet')
            return
        # 获取最新的消息
        latest_message = self.message_window[-1]
        # 创建新的消息
        command_msg = Target()
        command_msg.name = "command"
        command_msg.count = latest_message.count
        command_msg.time = latest_message.time
        command_msg.target = latest_message.target
        # 发布消息
        self.publisher_.publish(command_msg)
        self.counter += 1
        self.get_logger().info(f'Command {self.counter} published with count {latest_message.count}')

def main(args=None):
    rclpy.init(args=args)
    process_node = ProcessNode()
    rclpy.spin(process_node)
    process_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()