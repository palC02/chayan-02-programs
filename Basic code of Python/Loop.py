print("Printing current and previous number and their sum in a range(10)")
print()
previous_no =0

for i in range(1,11):
    sum=previous_no+i
    print("Crurrent Number",i)
    print("Previous Number",previous_no)
    print("Sum ",sum)
    previous_no=i