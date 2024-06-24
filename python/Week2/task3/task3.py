import firelink

while True:
    choose = input("Enter the name of website: ").lower()
    firelink.openlink(firelink.links[choose])