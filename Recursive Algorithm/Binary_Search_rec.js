function Binary_Search_rec(arr,x){
    let low=0;
    let high=arr.length-1;
    let mid;
    while (high>=low){
        mid=Math.floor((high-low)/2);
        if(arr[mid]==x)
            return mid;
        if(arr[mid]>x)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

arr = new Array(2,3,4,10,40);
x=10;
n=arr.length;
result=Binary_Search_rec(arr,x);
if(result==x)
    console.log("Element is present at index "+result);
else
    console.log("Element is not present");