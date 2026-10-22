const args = {...}

const count = tonumber(args[1]) or 32
const numbers = table.create<<number>>(count)
for index = 1, count do
    numbers[index] = math.random(0, 100)
end

const result = table.create(3, 0)

for index = 1, count - 1 do
    const left = numbers[index]
    const right = numbers[index + 1] or left
    if left > right then
        result[1] += 1
    end
end

do
    local min = math.huge
    local max = -math.huge
    local sum_even = 0
    local count_even = 0

    for index, number in numbers do
        if number > max then
            max = number
        end
        if number < min then
            min = number
        end
        if number % 2 == 0 then
            sum_even += number
            count_even += 1
        end
    end

    if count_even > 0 then
        const average_even = (sum_even / count_even)
        result[2] = max * min * average_even
    end
end

for index = 2, count - 1 do
    const neighbour_index_sum = index * 2
    if neighbour_index_sum == numbers[index] then
            result[3] += 1
    end
end

