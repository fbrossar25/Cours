import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-search',
  templateUrl: './search.component.html',
  styleUrls: ['./search.component.scss']
})
export class SearchComponent implements OnInit {

  propertyName = 'name';
  value = '';
  constructor(private router: Router) {}

  ngOnInit() {
  }

  search() {
    console.log(`Recherche pour ${this.propertyName}=${this.value}`);
    this.router.navigate([`list/${this.propertyName}/${this.value}`]);
  }
}
