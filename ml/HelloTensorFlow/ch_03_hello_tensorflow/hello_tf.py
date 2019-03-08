import os
import tensorflow as tf

# Eliminate TensorFlow warnings
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# tf.enable_eager_execution()
# print(tf.reduce_sum(tf.random_normal([1000, 1000])))

a = tf.constant([1.0, 2.0], name="a")
b = tf.constant([1.0, 2.0], name="b")
result = a + b
# print(a.graph is tf.get_default_graph())
print(result)