run <- function() {
  testData <- read.table("./data/test/X_test.txt")
  trainData <- read.table("./data/train/X_train.txt")
  dataSet <- rbind(testData, trainData)
  
  subjectTest <- read.table("./data/test/subject_test.txt")
  subjectSetTrain <- read.table("./data/train/subject_train.txt")
  subjectSet <- rbind(subjectTest, subjectSetTrain)
  
  yTest <- read.table("./data/test/y_test.txt")
  yTrain <- read.table("./data/train/y_train.txt")
  ySet <- rbind(yTest, yTrain)
  
  #dataSet <- read.table("./data/test/X_test.txt")
  #subjectSet <- read.table("./data/test/subject_test.txt")
  #ySet <- read.table("./data/test/y_test.txt")
  
  
  colnames(subjectSet) <- "subject"
  colnames(ySet) <- "activity"
  
  
  
  # Step 2
  
  features <- read.table("./data/features.txt")
  
  dataSet <- dataSet[,grepl("(mean\\(\\)|std\\(\\))",features[,2])]
  
  variableNames <- features[grepl("(mean\\(\\)|std\\(\\))",features[,2]),2]
  colnames(dataSet) <- variableNames
  
  dataSet <- cbind(dataSet, subjectSet)
  dataSet <- cbind(dataSet, ySet)
  
  sform <- as.formula(paste("cbind(", paste("`", names(dataSet)[1:66], "`", sep="", collapse=","),")~subject+activity")) 
  cleardata <- aggregate(sform, data=dataSet, mean)
  cd<<-cleardata
}