y=int(input())

def func(dist):
	if dist==0:
		return 1
	if dist<0:
		return 0
	s=0
	for i in range(3):
		s+=func(dist-(i+1))
	return s
	
def func_dp(n):
	x=[0]*(n+1)
	x[0]=1
	x[1]=1
	x[2]=2
	for i in range(3,n+1):
		x[i]=x[i-2]+x[i-3]+x[i-1]
	return x[n]

print(func_dp(y))				