"""
    ch_4 deep neural networks

    custom_loss.py
"""


import os
import tensorflow as tf
from numpy.random import RandomState

# Eliminate TensorFlow warnings
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# define the size of batch
batch_size = 8

# define the input and output
x = tf.placeholder(tf.float32, shape=(None, 2), name="x-input")
y_ = tf.placeholder(tf.float32, shape=(None, 1), name="y-input")

# define the structure of network
w1 = tf.Variable(tf.random_normal(([2, 1]), stddev=1, seed=1))
y = tf.matmul(x, w1)

loss_less = 10
loss_more = 1
loss = tf.reduce_sum(tf.where(tf.greater(y, y_), (y - y_) * loss_more, (y_ - y) * loss_less))
learning_rate = 0.08
train_step = tf.train.AdadeltaOptimizer(learning_rate).minimize(loss)

rdm = RandomState(1)
data_size = 128
X = rdm.rand(data_size, 2)
Y = [[x1 + x2 + rdm.rand() /10-0.05] for (x1,x2) in X]

with tf.Session() as sess:
    init_op = tf.global_variables_initializer()
    sess.run(init_op)

    STEP = 50000
    for i in range(STEP):
        start = (i * batch_size) % data_size
        end = min(start+batch_size, data_size)
        sess.run(train_step, feed_dict={x: X[start:end], y_:Y[start:end]})
        if i % 100 == 0:
            total_loss = sess.run(loss, feed_dict={x:X, y_:Y})
            print("After %d training step(s), total_loss on all data is %g" % (i, total_loss))

    print(sess.run(w1))
