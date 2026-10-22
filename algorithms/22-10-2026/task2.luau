const args = {...}

const count = tonumber(args[1]) or 32
const numbers = table.create<<number>>(count)
for index = 1, count do
    numbers[index] = math.random(0, 100)
end

const run_lengths = {}
do
    local run_length = 0
    local last_number = 0/0

    for index, number in numbers do
        if number == last_number then
            run_length += 1
            continue
        end

        if run_length > 1 then
            table.insert(run_lengths, run_length)
        end
        
        run_length = 1
        last_number = number
    end
end

print("n runs:", #run_lengths)
for index, length in run_lengths do
    print(`#{index}: {length}`)
end
