rankhospital <- function(state, outcome, num = "best") {
  ## Read outcome data
  data <- read.csv("outcome-of-care-measures.csv", colClasses = "character");
  onames <- c("heart attack", "heart failure","pneumonia");
  
  ## Check that state and outcome are valid
  if (! state %in% data$State) {
    stop("invalid state")
  } 
  
  if (! outcome %in% onames) {
    stop("invalid outcome")
  }
  
  outs <- c('Hospital.30.Day.Death..Mortality..Rates.from.Heart.Attack',
            'Hospital.30.Day.Death..Mortality..Rates.from.Heart.Failure',
            'Hospital.30.Day.Death..Mortality..Rates.from.Pneumonia');
  names(outs) <- onames;
  
  outname <- outs[[outcome]];
  
  
  
  mydata <- data[data$State==state, ]
  mydata[,outname]<-as.numeric(mydata[,outname] );
  
  ## Return hospital name in that state with the given rank
  ## 30-day death rate
 
  # Remove NA rows
  mydata<-mydata[!is.na(mydata[outname]),]
  
  # Order rows by name
  mydata<-mydata[order(mydata$Hospital.Name),]
 
  
  # Order by outcome
  mydata<-mydata[order(mydata[outname]),]
  
  
  if(num=="best") {
    mydata[1,]$Hospital.Name
  } else if(num=="worst") {
    tail(mydata,1)$Hospital.Name
  } else {
    #bestset <- mydata[mydata[outname]>num,]
    if(nrow(mydata)<num) {
      NA
    } else {
      mydata[num,]$Hospital.Name
    }
  }
}
