"""
    ch_5 MNIST

    variable_management.py
"""

import os
import tensorflow as tf

# Eliminate TensorFlow warnings
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

with tf.variable_scope("root"):
    print(tf.get_variable_scope().reuse)
    with tf.variable_scope("foo", reuse=True):
        print(tf.get_variable_scope().reuse)
        with tf.variable_scope("bar", reuse=True):
            print(tf.get_variable_scope().reuse)

def inference(input_tensor, reuse=False):
    with tf.variable_scope('layer1', reuse=reuse):
        weights = tf.get_variable("weights", [INPUT_NODE, LAYER1_NODE],
                                  initializer=tf.truncated_normal_initializer(stddev=0.1))
        biases = tf.get_variable("biases", [LAYER1_NODE], initializer=tf.constant_initializer(0.0))
        layer1 = tf.nn.relu(tf.matmul(input_tensor, weights) + biases)
    with tf.variable_scope('layer2', reuse=reuse):
        weights = tf.get_variable("weights", [LAYER1_NODE, OUTPUT_NODE],
                                  initializer=tf.truncated_normal_initializer(stddev=0.1))
        biases = tf.get_variable("biases", [OUTPUT_NODE], initializer=tf.constant_initializer(0.0))
        layer2 = tf.nn.relu(tf.matmul(input_tensor, weights) + biases)
    return layer2
