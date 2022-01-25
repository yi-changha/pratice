rm(list=ls())
View(iris)  # 150 종류로 이루어짐
head(iris, 3)  # 앞에서부터 3개 보기
tail(iris, 3)  # 끝에서부터 3개 보기
summary(iris)  # 수치데이터 요약
str(iris)  # data.frame 구성에 대한 요약

print(iris$Sepal.Width)  
attach(iris)  
print(Sepal.Width)
detach(iris)  