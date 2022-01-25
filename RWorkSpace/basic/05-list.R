# list
# 서로 다른 데이터 타입을 담을 수 있음
# 리스트에 저장된 데이터를 index 또는 key를 사용해 접근함
# 생성 함수 : list(key=value, key=value)

rm(list=ls())
a = list(name= 'Julie', age=25, h_w=c(160, 48))
v1 = a['name']  #List
v2 = a$name  #Scalar
v3 = a[['name']]  #Scalar
v4 = a[[3]]  #Scalar
str(a)