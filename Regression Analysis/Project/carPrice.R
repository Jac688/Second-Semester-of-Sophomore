X<-read.csv("G://Desktop//Second Term of Sophomore//Regression Analysis//Project//Regression//x_train.csv")
y<-read.csv("G://Desktop//Second Term of Sophomore//Regression Analysis//Project//Regression//y_train.csv")
data<-read.csv("G://Desktop//Second Term of Sophomore//Regression Analysis//Project//Regression")
X<-X[ , c("const","horsepower","carwidth","hatchback","dohcv","Highend")]
data<-data[,-1]

y<-y[ , c("price")]
attach(data)
plot(y)
model<-lm((price+1)~.,data)
summary(model)
par(mfrow=c(2,2))

plot(model)
model<-lm(sqrt(price)~.,data[-c(172,177, 20, 150, 60, 90, 69), ])
par(mfrow=c(2,2))
summary(model)
plot(model)
library(MPV)
press = PRESS(model)

rstudent(model)
hii<-hatvalues(model)
par(mfrow=c(2,2))
plot(model)

axis(2, at= seq(-3, 5, 0.5))

#cook<-cooks.distance(model)

library(car)  
qqPlot(model, labels=row.names(data), id.method="identify")

residplot <- function(model, nbreaks=10) {  
  z <- rstudent(model) 
  hist(z, breaks=nbreaks, freq=FALSE, 
       xlab="Studentized Residual", 
       main="Distribution of Errors") 
  rug(jitter(z), col="brown") 
  curve(dnorm(x, mean=mean(z), sd=sd(z)), 
        add=TRUE, col="blue", lwd=2) 
  lines(density(z)$x, density(z)$y, 
        col="red", lwd=2, lty=2) 
  legend("topright", 
         legend = c( "Normal Curve", "Kernel Density Curve"), 
         lty=1:2, col=c("blue","red"), cex=.7) 
} 

residplot(model) 