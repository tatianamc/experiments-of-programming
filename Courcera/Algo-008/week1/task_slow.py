with open('IntegerArray.txt', 'r') as f:
	read_data = [int(x) for x in f.read().splitlines()]
	f.closed

count = 0

#N = len(read_data)
N = 10000
for i in range(N):
	for j in range(i+1,N):
		if( read_data[i]  > read_data[j]):
			count+=1
print(count)