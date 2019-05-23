# total.py
# 2017/09/12

def total(init = 5, *nums, **kws):
    count = init
    for num in nums:
        count += num
    for key in kws:
        count += kws[key]
    return count

print(total(10, 1, 2, 3, vegetables=50, fruits=100))
