import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-search',
  templateUrl: './search.component.html',
  styleUrls: ['./search.component.scss']
})
export class SearchComponent implements OnInit {

  country: string;
  constructor(private router: Router) { }

  ngOnInit() {
  }

  search() {
    this.router.navigate(`search/name/${this.country}`);
  }
}
