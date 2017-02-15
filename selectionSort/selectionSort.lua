
function trace(array, length)
   for idx = 1, length, 1 do
      io.write(array[idx]);
      io.write(" ")
   end
   print("")
end

function selectionSort(array, length)
   for idx1 = 1, length-1, 1 do
      mindex = idx1
      for idx2 = idx1+1, length, 1 do
         if array[idx2] < array[mindex] then
            mindex = idx2
         end
      end
      array[idx1], array[mindex] = array[mindex], array[idx1]
      trace(array, length)
   end
end



--val1, val2 = swap(val1, val2)
array = {9,3,6,8,5,4,7,2,1}

selectionSort(array, 9)

