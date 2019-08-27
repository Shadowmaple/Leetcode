select FirstName, LastName, City, State
    from Person Left outer join Address
    on Person.PersonId = Address.PersonId
