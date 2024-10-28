function PlotColumn(path, column, plottitle, figureid)
  START_OF_DATA_X =csvread("../TM/watchdog.tm");
  TIMESCALER=1/(10^9);
  X= csvread(["../TM/", path]);
  START=1

#  for  i = 2:(size(X(:,1)))
#    if X(i,1) < X(i-1,1)
#      START=i
#    end
#  endfor

  figure(figureid);
  #plot(TIMESCALER*X(:,1)-START_OF_DATA_X(1,2),  X(:,column));
  plot(TIMESCALER*(X(:,1)-START_OF_DATA_X(1,1)),  X(:,column));
  title(plottitle);
  endfunction
