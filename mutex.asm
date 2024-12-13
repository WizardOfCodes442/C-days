mutex_lock:
    TSL REGISTER, MUTEX        #copy mutex to register and set mutex to 1
    CMP REGISTER,#0            #was mutex zero?
    JZE ok                     # if it was zero, mutex was unlocked , so return
    CALL thread_yield          # mutex is busy schedule another thread
    JMP mutex_lock             #try again
ok: RET                        # return to caller ,critical region is entered

mutex_unlock: 
    MOVE MUTEX,#0             # store a 0 in mutex
    RET                       # return to caller