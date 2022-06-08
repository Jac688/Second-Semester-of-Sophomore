# Input the data of Xi and Yi
x <- c(0, 10, 20, 30, 40, 50, 60)
y <- c(16, 27, 28, 39, 39, 48, 51)

# Calculate the value
avg_x <- sum(x)/ length(x)
avg_y <- sum(y)/ length(y)

Sxx <- sum((x-avg_x)^2)
Syy <- sum((y-avg_y)^2)
Sxy <- sum((x-avg_x)*(y-avg_y))

# Get the b0, b1
b1 <- Sxy / Sxx
b0 <- avg_y - b1*avg_x

# Output the result
result <- matrix(c(avg_x, avg_y ,Sxx, Syy, Sxy, b0, b1), nrow <- 1, ncol = 7, dimnames = list(c("Value"), 
          c("avg_x", "avg_y", "SSxx", "SSyy", "SSxy", "b0", "b1")))
#result[1,1] <- avg_x
#result[1,2] <- avg_y
#result[1,3] <- Sxx
#result[1,4] <- Syy
#result[1,5] <- Sxy
#result[1,6] <- b0
#result[1,7] <- b1
result

yi_h = b1*x + b0
residual = y - yi_h
residual 
# Plot the graphic, y = b0+b1*x
plot(x,y, type = "p", main = "The time spent going to school and time away from home after 7 am", col="blue", 
     xlab = "Time away from home after 7 am", ylab = "The time spent going to school")
abline(a=b0, b=b1, col="red", lwd=2)

