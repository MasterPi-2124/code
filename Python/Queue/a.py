fo=open("a.out","w")
class Node:

    def __init__(self,data=None):
        self.data=data
        self.next=None

class queue:

    def __init__(self):
        self.head=None

    def size(self):
        i=0
        node=self.head
        while (node is not None):
            i=i+1
            node=node.next
        return i

    def print(self):
        node=self.head
        if node is None:
            fo.write("NULL")
            return
        while (node is not None):
            fo.write(str(node.data))
            fo.write(" ")
            node=node.next
        fo.write("\n")

    def push(self,value=None):
        new_node = Node(value)
        node=self.head
        if node is None:
            self.head=new_node
        else:
            while node.next is not None:
                node=node.next
            node.next=new_node
    
    def front(self):
        node=self.head
        if node is None:
            return "NULL"
        else:
            return node.data

    def pop(self):
        node=self.head
        self.head=self.head.next
        node=None

    def empty(self):
        if not(self.size()):
            return 1
        return 0