# Count the number of 4 in list

numbers_element = int(input("Enter the number of element: "))

input_list = list(map(int, input("\nEnter the numbers : ").strip().split()))[:numbers_element]

print("the numbers of four in list : ",input_list.count(4))





