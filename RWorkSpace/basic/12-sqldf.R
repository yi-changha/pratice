install.packages('sqldf')
library(sqldf)

rm(list=ls())
data(iris) # data(iris) == r1
r1 = sqldf('select * from iris')
r2 = sqldf('select * from iris limit 5') # r2 == r4
r3 = sqldf('select count(*) from iris where species like "%sa"')
r4 = head(iris,5)