
function trace(array, length)
   for i = 1, length, 1 do
      io.write(array[i])
      io.write(" ")
   end
   print("")
end

function bubbleSort(array, length)
   flag = 1
   compare_count = 0
   swap_count = 0
   while flag == 1 do
      flag = 0
      for i = length, 2, -1 do
         if array[i] < array[i-1] then
            tmp = array[i]
            array[i] = array[i-1]
            array[i-1] = tmp
            flag = 1
            swap_count = swap_count + 1
            trace(array, length)
         end
         compare_count = compare_count + 1
      end
   end
   print("compare count : " .. compare_count)
   print("swap count : " .. swap_count)
end

array = {3,1,2,7,5,4,6}
length = 7

bubbleSort(array, length)



         
