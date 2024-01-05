

from typing import ContextManager


class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

    def __del__(self):
        print(self.data,"is dead")

class LinkedList:
    def __init__(self):
        self.dummy = Node(None)

    def isEmpty(self):
        return self.dummy.next == None

    def display(self):
        temp = self.dummy.next
        while temp != None:
            print(temp.data, end=' ')
            temp = temp.next
        print()

    def containsDuplicates(self, value):
        temp = self.dummy.next
        while temp != None:
            if temp.data != value:
                temp = temp.next
            else:
                return True

        return False

    def addFront(self, value):
        newNode = Node(value)
        newNode.next = self.dummy.next
        self.dummy.next = newNode

    def addBack(self, value):
        # find the end of the list
        temp = self.dummy
        while temp.next != None:
            temp = temp.next
        # attach the new node
        temp.next = Node(value)

    def removeFront(self):
        temp = self.dummy.next
        self.dummy.next = temp.next
        temp.next = None 

    def removeBack(self):
        temp = self.dummy.next
        trailer = self.dummy

        while temp.next != None:
            temp = temp.next
            trailer = trailer.next

        trailer.next = None

    def search(self, key):
        temp = self.dummy.next
        while temp != None:
            if temp.data == key:
                return temp
            temp = temp.next
        return None

    def remove(self, value):
        trailer = self.dummy
        temp = trailer.next

        while temp != None and temp.data != value:
            temp = temp.next
            trailer = trailer.next

        if temp != None:
            trailer.next = temp.next
            temp.next = None

    def count(self):
        counter = 0
        temp = self.dummy.next
        while temp != None:
            counter += 1
            temp = temp.next
        return counter;
        

def main():
    mylist = LinkedList()

    while True:
        print("-----------------")
        print("1. Add upfront")
        print("2. Add back")
        print("3. Remove front")
        print("4. Remove back")
        print("5. Print all")
        print("6. Check empty")
        print("7. Count list")
        print("8. Remove value")
        print("9. Search")
        print("11. Exit")
        print("-----------------")
        choice = int(input("Choose from the menu: "))
        match choice:
            case 1:
                value = int(input("Value to append in the list: "))
                if mylist.containsDuplicates(value):
                    print("Value is already in the list.")
                else:
                    mylist.addFront(value)
            case 2:
                value = int(input("Value to append in the list: "))
                if mylist.containsDuplicates(value):
                    print("Value is already in the list.")
                else:
                    mylist.addBack(value)
            case 3:
                mylist.removeFront()
            case 4:
                mylist.removeBack()
            case 5:
                mylist.display()
            case 6: 
                if mylist.isEmpty():
                    print("The list is empty.")
                else:
                    print("The list is not empty.")
            case 7: 
                print(f"The size of the list is : {mylist.count()}")
            case 8:
                value = int(input("Value to remove from the list: "))
                mylist.remove(value)
            case 9:
                value = int(input("Value to search in the list: "))
                if mylist.search(value) != None:
                    print("Value is in the list.")
                else:
                    print("Value is not in the list.")
            case 10:
                mylist.addFront(1)
                mylist.addFront(2)
                mylist.addFront(2)
                mylist.addFront(3)
                mylist.addFront(3)
                mylist.addFront(4)
                mylist.addFront(4)
                mylist.addFront(5)
                mylist.addFront(5)
                mylist.addFront(5)

                while mylist.containsDuplicates():

            case 11:
                exit()
            case _:
                continue
                
main()
