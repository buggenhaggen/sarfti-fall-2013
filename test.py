#!/usr/bin/python
import unittest

class Stack:
	_stack = []
	def __init__(self):
		self._stack = []
	def push(self, obj):
		return self._stack.append(obj)
	def pop(self):
		return self._stack.pop()
	def length(self):
		return len(self._stack)

class TestStack(unittest.TestCase):
	def test_alloc(self):
		st = Stack()
		self.assertEqual(st.length(), 0)
	def test_push(self):
		st = Stack()
		st.push(0)
		st.push(1)
		st.push(2)
		self.assertEqual(st.length(), 3)
	def test_pop(self):
		st = Stack()
		st.push(0)
		st.push(1)
		st.push(2)
		st.push("Test")
		self.assertEqual(st.length(), 4)
		elem = st.pop()
		self.assertEqual(elem, "Test")
		elem = st.pop()
		self.assertEqual(elem, 2)
		elem = st.pop()
		self.assertEqual(elem, 1)
		elem = st.pop()
		self.assertEqual(elem, 0)
		self.assertEqual(st.length(), 0)


if __name__ == "__main__":
	unittest.main()
