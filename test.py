#!/usr/bin/python
using unittest
+import unittest

class Stack:
  __stack = []
  def __init__(self):
    __stack = []
  def push(self, obj):
    return __stack.push()
  def pop(self):
  	return __stack.pop()
  def length(self):
  	return length(__stack)

class TestStack(unittest.TestCase):
  def alloc(self):
  	st = Stack()
  	self.assertEQ(st.length(), 0)
