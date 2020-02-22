"""
    ch_5 MNIST

    store_model.py
"""

import os
import tensorflow as tf

# Eliminate TensorFlow warnings
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


# # 声明两个变量并计算它们的和
# v1 = tf.Variable(tf.constant(1.0, shape=[1]), name="v1")
# v2 = tf.Variable(tf.constant(2.0, shape=[1]), name="v2")
#
# result = v1 + v2
#
# init_op = tf.global_variables_initializer()
#
# saver = tf.train.Saver()
#
# with tf.Session() as sess:
#     sess.run(init_op)
#     saver.save(sess, ".\models\model.ckpt")


# # 加载模型
# v1 = tf.Variable(tf.constant(1.0, shape=[1]), name="v1")
# v2 = tf.Variable(tf.constant(2.0, shape=[1]), name="v2")
# result = v1 + v2
#
# saver = tf.train.Saver()
# with tf.Session() as sess:
#     saver.restore(sess, ".\models\model.ckpt")
#     print(sess.run(result))


# # 直接加载持久化的图
# saver = tf.train.import_meta_graph(".\models\model.ckpt.meta")
# with tf.Session() as sess:
#     saver.restore(sess, ".\models\model.ckpt")
#     print(sess.run(tf.get_default_graph().get_tensor_by_name("add:0")))


v = tf.Variable(0, dtype=tf.float32, name="v")
for variables in tf.global_variables():
    print(variables.name)

ema = tf.train.ExponentialMovingAverage(0.99)
maintain_average_op = ema.apply(tf.global_variables())
for variables in tf.global_variables():
    print(variables.name)

saver = tf.train.Saver()
with tf.Session() as sess:
    init_op = tf.global_variables_initializer()
    sess.run(init_op)
    sess.run(tf.assign(v, 10))
    sess.run(maintain_average_op)
    saver.save(sess, ".\models\model.ckpt")
    print(sess.run([v, ema.average(v)]))
