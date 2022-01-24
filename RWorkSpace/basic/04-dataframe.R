# data.frame
# 엑셀의 WorkSheet와 같은 구조의 2차원 데이터
# '여러 가지 데이터 유형'을 가질 수 있음. 벡터 별로 다른 데이터 유형 가능
# 벡터가 모여 데이터 프레임을 구성함

# data.frame 생성 함수
# data.frame(vectors or matrices, strinfsAsFactors) # 벡터의 길이는 모두 같아야 함.
# data.frame(변수명=벡터, ... , stringsAsFactors)
#  stringsAsFactors를 TRUE로 지정하면 문자열을 factor형으로 저장함.

rm(list=ls())
name = c('tom', 'jerry', 'cindy', 'mark')
gender = c('f', 'm', 'f', 'm')
kor = c(90, 100, 80, 95)
eng = c(90, 95, 100, 80)
df1 = data.frame(name, gender, kor, eng)  # 4 obs. of 4 variables
df2 = data.frame(matrix(seq(1,9), nrow=3))
#  1   4   7
#  2   5   8
#  3   6   9

df3 = data.frame(gender = c('f', 'm', 'f', 'm'),
                 score = c(90, 100, 80, 95),
                 stringsAsFactors =  TRUE)
str(df3)
# gender : Factor w / 2 levels "f", "m" : 1 2 1 2
# score : num 90 100 80 95


rm(list=ls())
name = c('tom', 'jerry', 'cindy', 'mark')
gender = c('f', 'm', 'f', 'm')
kor = c(90, 100, 80, 95)
eng = c(90, 95, 100, 80)
df = data.frame(name, gender, kor, eng)  # 4 obs. of 4 variables
v1 = df[1, 3]  # 90
df1 = df[2,] # jerry m 100 95
v2 = df[, 'name'] # "tom" "jerry" "cindy" "mark"  #vector
v3 = df$name  # df$name == df[, 'name']
df2 = df[1] # 1번 열
# name
# tom
# jerry
# cindy
# mark

df3 = df['name']  # df['name'] == df[1]
v4 = df[[1]]  # "tom" "jerry" "cindy" "mark" # 1번 열, vector
df4 = df[seq(1,3), c(1, 2)]
#     name  gender
#  1   tom       f
#  2 jerry       m
#  3 cindy       f

df5 = df[, 2:4]  # 2~4열
#  gender kor eng
#1      f  90  90
#2      m 100  95
#3      f  80 100

#4      m  95  80
df6 = df[1:3]
#name gender kor
#1   tom      f  90
#2 jerry      m 100
#3 cindy      f  80
#4  mark      m  95

df7 = df[-2]
#name kor eng
#1   tom  90  90
#2 jerry 100  95
#3 cindy  80 100
#4  mark  95  80

df8 = df[-c(1, 3, 4)]
#gender
#1      f
#2      m
#3      f
#4      m