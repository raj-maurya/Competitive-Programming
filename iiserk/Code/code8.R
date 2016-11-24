
x=c(1,30,50,41,38,20,29,60)
y=c(60,45,9,30,35,55,26,8)
pdf("presentation3.pdf")
par(mfrow=c(3,2))
t=cor(x,y)
plot(x,col="Red",xlab="random x value",ylab="random y value",type="l")

lines(y,col="Blue")
d=paste("Random data,correlation", t)
title(d)

i=0
j=0
k=0
for(i in c(2,4))
{
p=c(1,117,23,86,2,3,5,12)
m=length(x)%/%i


a=matrix(0,nrow=i,ncol=m)
b=matrix(0,nrow=i,ncol=m)
for(j in 1:m)
{
for(k in 1:i)
{
a[k,j]=x[(k-1)*m+j]

}
}
for(j in 1:m)
{
for(k in 1:i)
{
b[k,j]=y[(k-1)*m+j]

}

}


r=matrix(0,nrow=i,ncol=i)

for(j in 1:i)
{
for(k in 1:i)
{
r[j,k]=cor(a[j,],b[k,])
}
}
r1=as.vector(r)
plot(r1,ylab="correlation",xlab="pair number",type="b",col=p[i])
b=paste0("Correlation dividing data in ", i ," parts")
title(b)
print(r)
}
j=rep(0,length(x))
m=length(x)-1
for(i in 2:m)
{
if(x[i]>x[i-1]&&x[i]>x[i+1])
j[i]=i
else if(x[i]<x[i-1]&&x[i]<x[i+1])
j[i]=i
}


k=rep(0,length(y))
n=length(y)-1
for(i in 2:n)
{
if(y[i]>y[i-1]&&y[i]>y[i+1])
k[i]=i
else if(y[i]<y[i-1]&&y[i]<y[i+1])
k[i]=i
}

j=which(j>0)
k=which(k>0)
m=length(j)
n=length(k)


if(m>1&&n>1)
{
a=rep(0,m-1)

for(i  in 1:m-1)
{
a[i]=j[i+1]-j[i]
}

e=max(a)


b=rep(0,n-1)

for(i  in 1:n-1)
{
b[i]=k[i+1]-k[i]
}

f=max(b)


a=matrix(0,nrow=m+1,ncol=max(e,f))
b=matrix(0,nrow=n+1,ncol=max(e,f))
for(i in 1:j[1])
a[1,i]=x[i]
l=length(x)-j[m]
for(i in 1:l)
a[m+1,i]=x[i+j[m]]




q=0



for(i in 2:m)
{
l=j[i]-j[i-1]

for(q in 1:l)
{
a[i,q]=x[q+j[i-1]]
}
}


for(i in 1:k[1])
b[1,i]=y[i]
l=length(y)-k[n]
for(i in 1:l)
b[n+1,i]=y[i+k[n]]




q=0



for(i in 2:n)
{
l=k[i]-k[i-1]

for(q in 1:l)
{
b[i,q]=x[q+k[i-1]]
}
}
}

if(m==1)
{
s=length(x)-j
e=max(j,s)

a=matrix(0,nrow=m+1,ncol=max(e,f))

for(i in 1:j)
a[1,i]=x[i]
l=length(x)-j
for(i in 1:l)
a[m+1,i]=x[i+j]

}
if(n==1)
{
f=length(y)-k
f=max(k,s)
b=matrix(0,nrow=n+1,ncol=max(e,f))
for(i in 1:k)
b[1,i]=y[i]
l=length(y)-k
for(i in 1:l)
b[n+1,i]=y[i+k]
}
i=1
j=1
a
b
m
r=matrix(0,nrow=m+1,ncol=n+1)
m=m+1
n=n+1
for(i in 1:m)
{
for(j in 1:n)
{
r[i,j]=cor(a[i,],b[j,])
}
}
r
r1=as.vector(r)
plot(r1,ylab="correlation",col="Green",type="l",xlab="pair number")
title("Correlation in dividing at inflexion point")
o=(m+1)*(n+1)
lines(rep(0,o),col="Red")

i=0
j=0
k=0

plot(rep(0,30),type="l",ylab="correlation",col="Purple",xlab="middle point",xlim=c(0,9),
ylim=c(-1,-.5))
for(i in c(4,6,8))
{
p=c("Red","Grey","Blue","Orange","Yellow","Green","Black","Violet")
m=floor(length(x)*i/10)
n=length(x)+1-m
c=rep(0,n)
d=rep(0,n)
for(j in 1:n)
{

q=m+j-1
c[j]=cor(x[c(j:q)],y[c(j:q)])
d[j]=floor((m+2*j-1)/2)
}
lines(d,c,col=p[i])
}
title("Sliding correlation by taking data parts")
lab=c("2/5th data","3/5th data","4/5th data")
legend("topleft",lab,lty=1,cex=.75,col=c("orange","green","violet"))
dev.off()
