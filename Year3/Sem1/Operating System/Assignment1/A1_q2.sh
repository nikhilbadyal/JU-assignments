echo -ne "Number of files in current working directory and in all of its sub-directories are : "
sudo find . -type f | wc -l

echo "Printing all the files in the current working directory and in all of its sub-directories "

find . -maxdepth 1 -mindepth 1 -type d | while read dir; do
  printf "%-15s : " "$dir"
  find "$dir" -type f | wc -l
done

echo "printing only those file names that have been created in the year 2018 and
2019 "
find . -type f -ls | grep '2018'
find . -type f -ls | grep '2020'

