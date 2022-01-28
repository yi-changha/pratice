# apply 계열 함수
#데이터 조작에 편리한 기능 제공, apply 함수가 가장 많이 사용됨.
#-for문 없이 milti-core 사용으로 빠르게 연산 가능
#-split -> apply -> combine 기능 제공, (데이터 분할 -> 함수 적용 -> 재결합)

rm(list=ls())
a = matrix(1:12, nrow=4)
r1 = apply(a, 1, sum) # MARGIN = 1, 행 기준 연산
r2 = apply(a, 2, sum) # MARGIN = 2, 열 기준 연산
r3 = apply(a, 1, mean) # 평균
r4 = apply(a, 2, max) # 최대값

rm(list = ls())
a = list(c(1,2,3), seq(1,9,2), seq(2,8,2))
r1 = lapply(a, sum) # 원소별로 합을 구함.
r2 = unlist(r1)
r3 = sapply(a,sum) # sapply = lapply + unlist
r4 = lapply(c(1, 2, 3), function(x) { x*2 -1 })

rm(list=ls())
a = c(1, 11, 2, 22, 3, 33, 4, 44)
b = rep(c(TRUE,FALSE), 4)
r1 = tapply(a, a<=10, sum)
r2 = tapply(a, c(1,1,2,2,3,3,4,4), sum)
r3 = tapply(iris$Sepal.Length, iris$Species, mean)
r4 = tapply(a, b, sum)