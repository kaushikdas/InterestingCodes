///////////////////////////////////////////////////////
// WIP     WIP     WIP
///////////////////////////////////////////////////////

#include <cstdio>

struct Date
{
  int year, month, day;
};

enum RepeatType
{
  NO_REPEAT,
  REPEAT_DAILY,
  REPEAT_EVERY_3_DAYS,
  REPEAT_EVERY_5_DAYS,
  REPEAT_EVERY_7_DAYS,
  REPEAT_EVERY_10_DAYS,
  REPEAT_MONTHLY,
  REPEAT_YEARLY
};

void init()
{
    
}

void addSchedule(int id, Date d, RepeatType rt, int rc)
{
    
}

void deleteSchedule(Date d, int mode)
{

}

int searchSchedule(Date d1, Date d2)
{
    return 0;
}

int main(int argc, char const *argv[])
{
  printf("Schedule Management\n");

  argc = argc;
  argv = argv;
  
  return 0;
}
