import os
import tensorflow as tf
from numpy.random import RandomState

# Eliminate TensorFlow warnings
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# define the size of batch
batch_size = 64

# define the structure of network
w1 = tf.Variable(tf.random_normal(([2, 3]), stddev=1, seed=1))
w2 = tf.Variable(tf.random_normal(([3, 1]), stddev=1, seed=1))

# define the input and output
x = tf.placeholder(tf.float32, shape=(None, 2), name="x-input")
y_ = tf.placeholder(tf.float32, shape=(None, 1), name="y-input")

a = tf.matmul(x, w1)
y = tf.matmul(a, w2)
y = tf.sigmoid(y)

cross_entropy = -tf.reduce_mean(y_ * tf.log(tf.clip_by_value(y, 1e-10, 1.0))
                                +(1-y_) * tf.log(tf.clip_by_value(1-y, 1e-10, 1.0)))
learning_rate = 0.05
train_step = tf.train.AdadeltaOptimizer(learning_rate).minimize(cross_entropy)

rdm = RandomState(1)
data_size = 10240
X = rdm.rand(data_size, 2)
Y = [[int(x1+x2) < 1] for (x1,x2) in X]

with tf.Session() as sess:
    init_op = tf.global_variables_initializer()
    sess.run(init_op)

    STEP = 100000
    for i in range(STEP):
        start = (i * batch_size) % data_size
        end = min(start+batch_size, data_size)
        sess.run(train_step, feed_dict={x: X[start:end], y_:Y[start:end]})
        if i % 1000 == 0:
            total_cross_entropy = sess.run(cross_entropy, feed_dict={x:X, y_:Y})
            print("After %d training step(s), cross_entropy on all data is %g" % (i, total_cross_entropy))

    print(sess.run(w1))
    print(sess.run(w2))