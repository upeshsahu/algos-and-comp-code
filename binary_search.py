x=list(map(int,input().split()))
n=x[0]
s=x[1]
a=list(map(int,input().split()))


def func(a,s):
	lo=0
	hi=len(a)-1
	

	while lo<=hi:
		mid=int((hi+lo)/2)
		if a[mid]==s:
			return mid
		elif a[mid]<s:
			lo=mid+1
		else:
			hi=mid-1
	
	return -1		
				
print(func(a,s))
				