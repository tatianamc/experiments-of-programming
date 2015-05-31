best <- function(state, outcome) {
  ## Read outcome data
  outcomes <- read.csv("outcome-of-care-measures.csv", colClasses = "character");
  
  outcs <- c("heart attack", "heart failure","pneumonia");
  
  ## Check that state and outcome are valid
  if (! state %in% outcomes$State) {
    stop("invalid state")
  } 
  
  if (! outcome %in% outcs) {
    stop("invalid outcome")
  }
  
  interoutcome <- outcomes[outcomes$State==state, ]
  
  if(outcome==outcs[1]) {
    vec<-as.numeric(interoutcome[,"Hospital.30.Day.Death..Mortality..Rates.from.Heart.Attack"]);
    m <- min(vec, na.rm=TRUE)
    aaa <- interoutcome[interoutcome$Hospital.30.Day.Death..Mortality..Rates.from.Heart.Attack==m,]
    names <-sort(aaa[["Hospital.Name"]])
    names[1]
  } else if (outcome==outcs[2]) {
    vec<-as.numeric(interoutcome[,"Hospital.30.Day.Death..Mortality..Rates.from.Heart.Failure"]);
    m <- min(vec, na.rm=TRUE)
    aaa <- interoutcome[interoutcome$Hospital.30.Day.Death..Mortality..Rates.from.Heart.Failure==m,]
    names <-sort(aaa[["Hospital.Name"]])
    names[1]
  } else {
    vec<-as.numeric(interoutcome[,"Hospital.30.Day.Death..Mortality..Rates.from.Pneumonia"]);
    m <- min(vec, na.rm=TRUE);
    aaa <- interoutcome[interoutcome$Hospital.30.Day.Death..Mortality..Rates.from.Pneumonia==m,]
    names <-sort(aaa[["Hospital.Name"]])
    names[1]
  }
  ## Return hospital name in that state with lowest 30-day death
  ## rate
}