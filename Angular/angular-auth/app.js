'use strict';

// Declare app level module which depends on views, and components
/*angular.module('myApp', [
  'ngRoute',
  'myApp.view1'
]).
config(['$routeProvider', function($routeProvider) {
  $routeProvider.otherwise({redirectTo: '/view1'});
}]);*/



var app = angular.module('myApp', []);
app.config(function($httpProvider) {
 //$httpProvider.defaults.headers.common["X-Requested-With"] = 'XMLHttpRequest';
 $httpProvider.defaults.useXDomain = true;
});

app.run(function($http) {
  //$http.defaults.headers.common.Authorization = 'Basic '+btoa("admin:123456");
});


  app.controller('home', function($rootScope,$scope, $http) {
  
    /*var authenticate = function(credentials, callback) {

    var headers = credentials ? {authorization : "Basic "
        + btoa(credentials.username + ":" + credentials.password)
    } : {};

    $http.get('http://localhost:8080/user', {headers : headers}).success(function(data) {
      if (data.name) {
        $rootScope.authenticated = true;
      } else {
        $rootScope.authenticated = false;
      }
      callback && callback();
    }).error(function() {
      $rootScope.authenticated = false;
      callback && callback();
    });

  }*/
  //authenticate();
  //$scope.credentials = {"username":"admin", "password":"123456"};
  
  /*$scope.login = function() {*/
     // authenticate($scope.credentials, function() {
     //   if ($rootScope.authenticated) {
          //$location.path("/");
		
     //     $scope.error = false;
//		  alert("ok");
		  
		  //$http.defaults.headers.common = {"Access-Control-Request-Headers": "accept, origin, authorization"}; 
		  //$http.defaults.headers.common = {"Access-Control-Allow-Credentials:": "true"}; 
		  //var config = {"withCredentials":true};
		  //$http.defaults.headers.common['Authorization'] = 'Basic ' + btoa("admin:123456");
		  //var bla = 'Basic ' + btoa("admin:123456");
		  $http.get('http://localhost:8080/resource/bb',{"withCredentials": true}).success(function(data) {
				$scope.greeting = data;
			  }).error(function(data, status) {
			  alert(data+' '+status)
			 
       }); 
        //} else {
          //$location.path("/login");
          //$scope.error = true;
		//  alert("ff");
        //}
      //});
  //};
  // $http.defaults.headers.common = {"Access-Control-Request-Headers": "accept, origin, authorization"}; //you probably don't need this line.  This lets me connect to my server on a different domain
	  //$http.defaults.headers.common['Authorization'] = 'Basic ' + "YWRtaW46MTIzNDU2"; //Base64.encode('admin' + ':' + '123456');
	  /*$http.get('http://localhost:8080/resource/bb').success(function(data) {
		$scope.greeting = data;
	  })*/
})