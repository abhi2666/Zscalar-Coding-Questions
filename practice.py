## {1, 2, 3, 4 , 5}
l= [1,2, 3, 4, 5]
a = c = 0
for i in range(0,len(l)):
    if i % 2 == 0:
        a +=l[i]*l[i]
    else:
        c += l[i]*l[i]*l[i]
print(a+c)