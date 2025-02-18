num_list = [3, 4, 5, 1, -44, 5, 10, 12, 33, 1]
k = 3
start_indexes = list(range(0, len(num_list) - k + 1))
end_indexes = list(range(k, len(num_list) + 1))

result = []
for start_index, end_index in zip(start_indexes, end_indexes):
    sub_list = num_list[start_index: end_index]
    result.append(max(sub_list))

print(result)
