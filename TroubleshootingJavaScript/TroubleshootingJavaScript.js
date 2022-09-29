/*
    For this assignment you will need to examine the JavaScript below and determine the syntax issues - 
    and then correct them.  Each set of code could have one or many issues that must be correct.  
    Note each section of code that needs to be evaluated is separated by a series of '----------------------'.  
    I recommend copying the code snippets into Visual Studio Code to view and evaluate it.  
    Once you have found a location for correction, correct the code and add a comment explaining what the error was.
*/


function addTwoNumbers(intOne, intTwo){
    if(!intOne && !intTwo){
        return 0;
        if(intOne){
            if(intTwo){ //correction
                return intOne + intTwo;
            } 
            else {
                return intOne;
            }
        }
    }
return intTwo;
}
//CORRECTIONS: Corrected parenthesis & brackets on inner most if statement. Corrected indentation for more readability.
--------------------------------------

$('#cboEmployeeType').change(function() {
    if($('#cboEmployeeType').val() == 'FULL'){
        $('#divHours').slideUp(); //correction
        $('#divHours').css('display','none'); //correction
        $('#divHours').addClass('d-none');
    }else {
        $('#divHours').removeClass('d-none').slideDown;
    }
})
//CORRECTIONS: Removed "/" on line 29 and removed "//" on line 30
--------------------------------------

function buildEmployeeCard(){
    $.each(arrEmployees,function(i,person){
        if(person.FirstName != 'John'){
            let strHTML;
            strHTML += '<div class="card col-6 offset-3 mt-5">';
            strHTML += '<h3 class="text-center"><a href="mailto:' + person.Email + '">' + person.FirstName + ' ' + person.LastName + '</a></h3>';
            strHTML += '<h4 class="text-center">' + person.Postion +'</h4>';
            strHTML += '<h4 class="mt-3">Profile Details</h4>';
            strHTML += '<p>Hourly Rate: ' + person.HourlyRate + '</p>';
            strHTML += '<p>Address:  586 Southern Lane, Cookeville, TN 38506</p>';
            strHTML += '<p>Assignment:  Clement Hall</p>';
            strHTML += '<div class="form-group">';
            strHTML += '<label for="txtPayRate">Pay Rate</label>';
            strHTML += '<input id="txtPayRate">';
            strHTML += '</div>';
            strHTML += '</div>';
            $('body').append(strHTML);
        }
    });
} //correction
    //CORRECTIONS: Added missing "}" for the outer function
--------------------------------------

var arrEmployees;
$.getJSON("https://www.swollenhippo.com/getEmployeesByAPIKey.php?APIKey=Mickey2021!", function(result){ //
    console.log(result);
    arremployees = result;
    buildEmployeeCard();
    $.each(result,function(i,person){
        console.log(Person.FirstName);
        console.log(person.FirstName + ' ' + person.LastName);
        $('#txtEmail').val(person.Email);
    }); //correction
}); //correction
//CORRECTIONS: Added ";" to last line, removed extra ")" in line 63. Added missing ");" to line 71.

--------------------------------------

$(document).on('click','#btnHideWelcome',function(){
    $('#divWelcome').slideToggle();
    $('#divData'.slideToggle);
    $('#btnViews').slideToggle;
}); //correction
//CORRECTIONS: Added missing ";" on last line.

--------------------------------------

$(document).on('click','.btnCalculate',function(){
    let decWage = $(this).closest('.card').find('.spanRate').text();
    let decTax = $(this).closest('.card').find('.spanTax').text();
    let decGoal = $(this).closest('card').find('.txtGoal').val();
    let decTaxedWage = decWage * (1.00 - decTax); //correction
    let decHours = decGoal/decTaxedWage;
    if(decHours > 40){
        decGoal = decGoal - (40 * (decWage * (1.00 - decTax)));
        decHours = decGoal/(decWage * ((1.00 - decTax)*1.5)); //correction
        decHours += 40;
    } //correction
    $(this).closest('.card').find('.spanHours').text(Math.round((decHours + Number.EPSILON) * 100) / 100);
}); //correction
//CORRECTIONS: Added missing ")" on line 90. Added missing "}" on line 96. Added missing ";" on line 98. Moved "(" for correct order of operations on line 94.

--------------------------------------

function buildEmployeeTableRow(Employee){
    return '<tr><td>' + Employee.FirstName + '</td><td>' + Employee.LastName + '</td><td>' + Employee.Title + '</td><td>' + calculateTotalPay(Employee.HourlyWage,employee.Hours,Employee.TaxRate) + '</td></tr>'; //correction *2
}                                             //correction                                                                                                                                           //correction
//CORRECTIONS: Added missing " ' " on first pair of closing </td><td> and on the last pair of closing </td><td>.

--------------------------------------

function calculateTotalPay(decPayRate, decHours, decTaxRate){
    decOverTime = 0.00;
    if(decHours > 40){ //correction
        decOvertime = dechours - 40;
        decHours = 40;
    }
    return Math.round((((((decHours * decPayRate) + (decOverTime * decPayRate * 1.5)) * (1- decTaxRate)) + Number.EPSILON) * 100) / 100); //correction
}
//CORRECTIONS: Added missing ")" in if statement on line 112. Added outer most pair of "()" around entire equation in round() function on line 116.
