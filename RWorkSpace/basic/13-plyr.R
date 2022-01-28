install.packages('plyr')
library(plyr)

rm(list=ls())
set.seed(1)
r1 = data.frame(year=rep(2018:2021, each=5),count=round(runif(20, 1, 40)))
r2 = ddply(r1, 'year', function(x){
  mean.count = mean(x$count) # 평균
  sd.count = sd(x$count) # 표준편차
  cv = sd.count/mean.count  # cv 계수
  data.frame(m.count = mean.count, s.count=sd.count, cv.count = cv)
})

# 'year' == .(year)

r3 = ddply(r1, .(year), summarise, mean.count=mean(count))
r4 = ddply(r1, .(year), transform, total.count=sum(count))

r5 = data.frame(A=c(1,2,3,4), B=c(4,5,6,7), C=c(1,3,5,7))
r6 = adply(r5, 1, sum) # 행별 합계
r7 = adply(r5, 2, sum) # 열별 합계