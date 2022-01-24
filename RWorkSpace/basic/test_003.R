# matrix(행렬)
# 데이터의 형태가 2차원으로 행(row)과 열(column)로 구성
# 하나의 데이터 유형만 가능, 역행렬은 solve()로 구함

# 행렬 생성 함수
# matrix(data=NA, nrow = 1, ncol=1, byrow=FALSE, dimnames=NULL)
#  byrow : 값의 입력 방향 '열'이며, TRUE로 지정 시 '행' 방향으로 변경됨.
#  dimnames : 각 차원의 이름
# rbind(vectors or matrices), cbind(vectors or matrices) 

rm(list = ls())
m1 = matrix(seq(1, 10), nrow=5, byrow=TRUE)
m2 = matrix(seq(1, 6), ncol=3)
m3 = rbind(seq(1, 3), seq(4, 6), seq(7, 12))
m4 = cbind(seq(1, 3), seq(4, 6))


rm(list = ls())
m = matrix(seq(1, 12), nrow=4, ncol=3)
#  1   5   9
#  2   6  10
#  3   7  11
#  4   8  12
m1 = m[2, 3]  # 10
m2 = m[3,]  # 3, 7, 11
m3 = m[,-2]
#  1   9
#  2  10
#  3  11
#  4  12
m4 = m[c(2,3), 2]  # 6 7   # 2~3번행의 2번째 열
m5 = m[c(TRUE, FALSE, FALSE, TRUE),] ## 1, 4번행 TRUE, 열은 모두
#  1   5   9
#  4   8  12


rm(list=ls())
a1 = array(1:12, dim=c(3,2,2))  # 3행 2열이 2개 있는 3차원 행렬
a2 = array(1:6, dim =c(2,3))
#  1   3   5
#  2   4   6