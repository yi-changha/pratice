rm(list=ls())
data("airquality")
colnames(airquality) = tolower(colnames(airquality))

# is.na(x)
r1 = is.na(airquality$ozone)
# x의 포함된 값이 NA인지 아닌지 각각에 대해 TRUE, FALSE 값을 반환함.
# logical을 산술 연산이 가능하기 때문에 is.na함수 적용 후,
#sum 함수를 사용해 결측치 개수를 파악할 수 있음.
r2 = sum(r1)

r3 = table(is.na(airquality$ozone))
r4 = apply(airquality, 2, function(x) { sum(is.na(x))})

# complete.cases(x)
air_na = airquality[!complete.cases(airquality),]
# x가 결측치를 가지고 있지 않은 완전한 데이터인지 확인하는 함수
# 행 별로 결측치 가 없으면 TRUE, 있으면 FALSE를 반환함

air_com = airquality[complete.cases(airquality),]
# x!complete.cases(x),] : indexing을 사용하여 결측치(NA) 행만 추출
# x[complete.cases(x),] : indexing을 사용하여 결측치(NA)를 포함하지 않은 행 추출

r5 = na.omit(airquality)
#na.omit(x) : 결측치(NA)가 있는 행 전체 삭제