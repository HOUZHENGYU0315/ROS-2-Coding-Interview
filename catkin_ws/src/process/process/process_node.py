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

        # PID 控制器的状态变量
        self.set_point = [0.0, 0.0, 0.0]  # 目标值
        self.process_variable = [0.0, 0.0, 0.0]  # 过程变量
        self.integral = [0.0, 0.0, 0.0]  # 积分项
        self.previous_error = [0.0, 0.0, 0.0]  # 上一次的误差

        # PID 增益参数
        self.Kp = 1.0  # 比例增益
        self.Ki = 0.1  # 积分增益
        self.Kd = 0.01  # 微分增益

    def listener_callback(self, msg):
        # 将接收到的消息存储到窗口中
        self.message_window.append(msg)

    def timer_callback(self):
        if not self.message_window:
            self.get_logger().warn('No messages received yet')
            return
        # 获取最新的消息
        latest_message = self.message_window[-1]

        # 计算误差
        error = [
            self.set_point[0] - self.process_variable[0],
            self.set_point[1] - self.process_variable[1],
            self.set_point[2] - self.process_variable[2]
        ]

        # 计算积分项
        self.integral[0] += error[0] * 0.01  # 0.01 是定时器的周期
        self.integral[1] += error[1] * 0.01
        self.integral[2] += error[2] * 0.01

        # 计算微分项
        derivative = [
            (error[0] - self.previous_error[0]) / 0.01,
            (error[1] - self.previous_error[1]) / 0.01,
            (error[2] - self.previous_error[2]) / 0.01
        ]

        # 更新上一次的误差
        self.previous_error = error

        # 计算 PID 输出
        output = [
            self.Kp * error[0] + self.Ki * self.integral[0] + self.Kd * derivative[0],
            self.Kp * error[1] + self.Ki * self.integral[1] + self.Kd * derivative[1],
            self.Kp * error[2] + self.Ki * self.integral[2] + self.Kd * derivative[2]
        ]

        # 更新过程变量
        self.process_variable[0] += output[0] * 0.01
        self.process_variable[1] += output[1] * 0.01
        self.process_variable[2] += output[2] * 0.01
        
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