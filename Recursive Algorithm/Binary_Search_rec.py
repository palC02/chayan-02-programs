def Binary_Search_rec(arr,low,high,x):
    while low<=high:
        mid=low+(high+low)//2

        if arr[mid]==x:
            return mid
        elif arr[mid]<x:
            low=mid+1
        else:
            high=mid-1
    return -1

if __name__ == '_main_':
    arr=[2,3,4,10,40]
    x=10
    result=Binary_Search_rec(arr,0,len(arr)-1,x)
    if result!=-1:
        print("Element is present at index: ",result)
    else:
        print("Element is not present")
    