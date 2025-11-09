#!/bin/bash

# ----------------------------------------------------------
# Address Book Program (Shell Script)
# ----------------------------------------------------------

# Print title
echo -e "Address Book\n"

# Ask for file name and create the file if not exists
echo -e "Enter Address Book File Name:"
read fname
touch $fname

# Add header row (only if file is empty)
if [ ! -s $fname ]; then
    echo -e "id\tname\tmobile_no\tsalary\tlocation" >> $fname
fi

ch=0

# Main loop
while [ $ch -ne 7 ]
do
    # Menu options
    echo -e "\n---------------- MENU ----------------"
    echo "1) Create Address Book (Multiple Records)"
    echo "2) View Address Book"
    echo "3) Insert a Record"
    echo "4) Delete a Record"
    echo "5) Modify a Record"
    echo "6) Search a Record"
    echo "7) Exit"
    echo "---------------------------------------"
    echo "Enter Your Choice:"
    read ch

    case $ch in

        # ----------------------------------------------------------
        # 1. Create Address Book (insert multiple records)
        # ----------------------------------------------------------
        1)
            echo "Enter number of records:"
            read n

            for((i=1;i<=n;i++))
            do
                echo "Enter id:"
                read id
                echo "Enter name:"
                read name
                echo "Enter mobile number:"
                read mno
                echo "Enter salary:"
                read sal
                echo "Enter location:"
                read loc

                echo -e "$id\t$name\t$mno\t$sal\t$loc" >> $fname
            done
        ;;

        # ----------------------------------------------------------
        # 2. View Address Book
        # ----------------------------------------------------------
        2)
            echo -e "\n------ Address Book Content ------"
            cat $fname
        ;;

        # ----------------------------------------------------------
        # 3. Insert a Single Record
        # ----------------------------------------------------------
        3)
            echo "Enter id:"
            read id
            echo "Enter name:"
            read name
            echo "Enter mobile number:"
            read mno
            echo "Enter salary:"
            read sal
            echo "Enter location:"
            read loc

            echo -e "$id\t$name\t$mno\t$sal\t$loc" >> $fname
        ;;

        # ----------------------------------------------------------
        # 4. Delete Record by ID
        #    grep -w → exact match
        #    -v → remove matching line
        # ----------------------------------------------------------
        4)
            echo "Enter Employee ID to delete:"
            read id

            if grep -w $id $fname > /dev/null
            then
                grep -wv $id $fname > temp && mv temp $fname
                echo "Record deleted."
            else
                echo "Record not found."
            fi
        ;;

        # ----------------------------------------------------------
        # 5. Modify a Record
        #    Delete old record, insert new updated record
        # ----------------------------------------------------------
        5)
            echo "Enter Employee ID to modify:"
            read id

            if grep -w $id $fname > /dev/null
            then
                grep -wv $id $fname > temp && mv temp $fname
                
                echo "Enter new id:"
                read nid
                echo "Enter new name:"
                read name
                echo "Enter new mobile number:"
                read mno
                echo "Enter new salary:"
                read sal
                echo "Enter new location:"
                read loc

                echo -e "$nid\t$name\t$mno\t$sal\t$loc" >> $fname
                echo "Record modified."

            else
                echo "Record not found."
            fi
        ;;

        # ----------------------------------------------------------
        # 6. Search a Record
        # ----------------------------------------------------------
        6)
            echo "Enter Employee ID to search:"
            read id

            if grep -w $id $fname
            then
                echo "Record found."
            else
                echo "Record not found."
            fi
        ;;

        # ----------------------------------------------------------
        # 7. Exit
        # ----------------------------------------------------------
        7)
            echo "Exiting program..."
        ;;

        # ----------------------------------------------------------
        # Invalid Choice
        # ----------------------------------------------------------
        *)
            echo "Invalid choice, try again."
        ;;
    esac
done
