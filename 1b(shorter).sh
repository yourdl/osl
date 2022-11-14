#create address book
Create()
{
        echo "Enter address book name"
        read book
       
        res=`ls | grep $book | wc -w`
       
        if [ $res -gt 0 ]
        then
                echo "Error: file already Exist."
        else
                touch $book
                echo "$book is created"
        fi                
}


Insert()
{
        echo "Enter address book name"
        read book
       
        res=`ls | grep $book | wc -w`
       
        if [ $res -gt 0 ]
        then
                echo "Enter First name, Last name ,email, Mobile number"
                read fname lname email mobile
                       
                        record=`echo $fname $lname $email $mobile`
                       
                        echo $record >> $book  #  >> will append the data
                        echo "Record Inserted !"    
        else
                echo "Error: file not Exist. create new file !"
        fi                
}

Modify()
{
        echo "Enter address book name"
        read book
       
        res=`ls | grep $book | wc -w`
       
        if [ $res -gt 0 ]
        then
                echo "Enter email"
                read email
                       
                        eml=`cat $book | grep $email | wc -w`
                         
                        if [ $eml -gt 0 ]
                        then
                                echo "Enter to modify the record: fname lname mobile!"
                                read fname lname mobile
                                new=`echo $fname $lname $email $mobile`
                                old=`cat $book | grep $email`
                                 
                                echo "Old Record: $old"
                                echo "new Record: $new"
                                 
                                sed -i s/"$old"/"$new"/g $book
                                echo "Record Modified !"
                        else
                                echo "Mail is not existing!"
                        fi                
        else            
                echo "Error: file not Exist. create new file !"
        fi                
}

#display address book
Display()
{
        echo "Enter address book name"
        read book
       
        res=`ls | grep $book | wc -w`
       
        if [ $res -gt 0 ]
        then
                cat $book
        else
                echo "Error: file not Exist. create new file !"
        fi                
}

Delete()
{
        echo "Enter address book name"
        read book
       
        res=`ls | grep $book | wc -w`
       
        if [ $res -gt 0 ]
        then
                echo "Enter email"
                read email
                       
                        eml=`cat $book | grep $email | wc -w`
                         
                        if [ $eml -gt 0 ]
                        then
                                old=`cat $book | grep $email`
                                 
                                sed -i s/"$old"//g $book
                                sed  -i /^$/d $book
                                echo "Record Deleted !"
                        else
                                echo "Mail is not existing!"
                        fi                
        else            
                echo "Error: file not Exist. create new file !"
        fi                
}



while [ true ]
do
        echo "****MENU***"
        echo "1.Create"
        echo "2.Insert"
        echo "3.Display"
        echo "4.Modify"
        echo "5.Delete"
        echo "6.Exit"
       
        echo "Enter Choice"
        read choice
       
        case $choice in
               1) Create;;
               
               2) Insert;;
               
               3) Display;;
               
               4) Modify;;
               
               5) Delete;;
               
               6) exit ;;
               
               *) echo "Wrong Choice !";;
        esac
done
