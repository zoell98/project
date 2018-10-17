cp ./log.log ~/
Num_rev_stu=`grep -o "STUDENT" log.log | wc -l`
echo "Number of revise student:"
echo $Num_rev_stu
Num_rev_cla=`grep -o "COURSE" log.log | wc -l`
echo "Number of revise course:"
echo $Num_rev_cla


read -p "please input student's number:" stu_num
grep "STUDENT" log.log | awk '{if($3=="'$stu_num'"){printf("%s\n",$0)}}'


read -p "please input course number:" cla_num
grep "COURSE" log.log | awk '{if($3=="'$cla_num'"){printf("%s\n",$0)}}'

