rankall <- function(outcome, num = "best") {
  ## Read outcome data
  data <- read.csv("outcome-of-care-measures.csv", colClasses = "character");
  onames <- c("heart attack", "heart failure","pneumonia");
    
  if (! outcome %in% onames) {
    stop("invalid outcome")
  }
  
  outs <- c('Hospital.30.Day.Death..Mortality..Rates.from.Heart.Attack',
            'Hospital.30.Day.Death..Mortality..Rates.from.Heart.Failure',
            'Hospital.30.Day.Death..Mortality..Rates.from.Pneumonia');
  names(outs) <- onames;
  outname <- outs[[outcome]];
  
  
  # make all value as number
  data[,outname]<-as.numeric(data[,outname] );
  
  
  # Remove NA rows
  data<-data[!is.na(data[outname]),]
  # Order rows by name
  data<-data[order(data$Hospital.Name),]
  # Order by outcome
  data<-data[order(data[outname]),]
  
  if(num=="best") {
    num=1
  }
  
  isWorst = num =="worst";
  
  ## For each state, find the hospital of the given rank
  # get all States
  hospital <- c()
  state <- c()
  for(st in unique(data$State)) {
    
    thisstate <- data[data$State==st, ]
    
    if(isWorst) {
      num <- nrow(thisstate)
    }
    
    if(nrow(thisstate)<num) {
      hospital<-c(hospital,NA)
    } else {
      hospital<-c(hospital,thisstate[num,]$Hospital.Name)
    }
    
    state<-c(state,st)
  }
  
  
  ## Return a data frame with the hospital names and the
  ## (abbreviated) state name
  df <- data.frame(hospital, state)
  df <- df[order(df$state),]
}