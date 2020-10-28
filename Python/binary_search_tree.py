class Node:
  def __init__(self, data):
    self.left = None
    self.right = None
    self.data = data

  def insert(self, data):
    if self.data:
      if data < self.data:
        if self.left is None:
            self.left = Node(data)
        else:
            self.left.insert(data)
      elif data > self.data:
        if self.right is None:
             self.right = Node(data)
        else:
            self.right.insert(data)
    else:
      self.data = data

  def search(self, value):
    if value < self.data:
        if self.left is None:
            return str(value) + " is not found"
        else:
            return self.left.search(value)
    elif value > self.data:
        if self.right is None:
            return str(value) + " is not found"
        else:
            return self.right.search(value)
    else:
        return str(self.data) +  " is found"
