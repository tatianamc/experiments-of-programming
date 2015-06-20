run <- function() {
  #
  # Step 1: Merges the training and the test sets to create one data set.
  #
  testData <- read.table("./data/test/X_test.txt")
  trainData <- read.table("./data/train/X_train.txt")
  dataSet <- rbind(testData, trainData)
  
  subjectTest <- read.table("./data/test/subject_test.txt")
  subjectSetTrain <- read.table("./data/train/subject_train.txt")
  subjectSet <- rbind(subjectTest, subjectSetTrain)
  
  yTest <- read.table("./data/test/y_test.txt")
  yTrain <- read.table("./data/train/y_train.txt")
  ySet <- rbind(yTest, yTrain)
  
  colnames(subjectSet) <- "subject"
  colnames(ySet) <- "activity"
  
  #
  # Step 2: Extracts only the measurements on the mean and standard deviation for each measurement. 
  #
  features <- read.table("./data/features.txt")
  dataSet <- dataSet[,grepl("(mean\\(\\)|std\\(\\))",features[,2])]
  
  
  #
  # Step 4: Appropriately labels the data set with descriptive variable names. 
  #
  variableNames <- features[grepl("(mean\\(\\)|std\\(\\))",features[,2]),2]
  colnames(dataSet) <- variableNames
  
  # Bind y and activity
  dataSet <- cbind(dataSet, subjectSet)
  dataSet <- cbind(dataSet, ySet)
  
  
  #
  # Step 3: Uses descriptive activity names to name the activities in the data set
  #
  activityLabels <- read.table("./data/activity_labels.txt")
  dataSet$activity <- factor(dataSet$activity, levels = activityLabels[,1], labels = activityLabels[,2])
  
  
  #
  # Step 5: From the data set in step 4, creates a second, independent tidy data set with the average of each variable for each activity and each subject.
  #
  # get formula for aggregate 
  sform <- as.formula(paste("cbind(", paste("`", names(dataSet)[1:66], "`", sep="", collapse=","),")~subject+activity")) 
  cleardata <- aggregate(sform, data=dataSet, mean)
  
  # return result
  cleardata
}