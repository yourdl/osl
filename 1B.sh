book="phone_book.txt"
echo "::Choose any 1 of the following::
1.ADD CONTACT
2.VIEW CONTACT
3.UPDATE CONTACT
4.DELETE CONTACT
5.EXIT"
read choice

a=1 b=2 c=3 d=4 e=5

if [ $choice -eq 1 ]
then 
echo -n "Enter Name::"    #in same line terminal work
read name
echo -n "Enter Number::"
read number

echo "$name::$number">>$book  #to append
echo "Contact Saved!"

sh main.sh

elif [ $choice -eq 2 ]
then 
echo "::Content of $book is ::"
cat -n $book  #gives number to lines

sh main.sh
elif [ $choice -eq $c ];
then 
cat -n $book

echo "Which contact you want change"

echo "Enter the NAME::" 
read name 
echo "Enter Current NUMBER::"
read number

echo "Enter the New NAME::"
read n_name

echo "Enter the New NUMBER::"
read n_number

sed -i 's/'$name'/'$n_name'/g' $book   #sed is command for change , i is for edit , s is for substitution and  g is for global change

sed -i 's/'$number'/'$n_number'/g' $book

echo "Updated List::"

cat $book

sh main.sh

elif [ $choice -eq $d ]
then

echo "Enter the Name which you want to delete::"
read name
grep -v $name $book > temp.txt   #grep is used to search the content and -v is used for printing all the llines that do not match the pattern(name).
cp temp.txt $book
cat $book

sh main.sh

elif [ $choice -eq $e ]
then
break

else
echo "You have entered a wrong choice! Try Again!"
sh main.sh
fi
