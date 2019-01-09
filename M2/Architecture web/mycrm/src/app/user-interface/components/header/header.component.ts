import { VersionService } from 'src/app/shared/services/version.service';
import { Component, OnInit } from '@angular/core';
import {tap, filter} from 'rxjs/operators';
import { BehaviorSubject } from 'rxjs';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.scss']
})
export class HeaderComponent implements OnInit {
  public title = 'My crm';
  public open = false;
  version: number;
  versionObservable: BehaviorSubject<number>; r;
  constructor(private versionService: VersionService) { }

  ngOnInit() {
    // this.versionService.getObservable().pipe(
    //   tap((d) => console.log('unfiltered ' + d)),
    //   filter((x) => x < 20),
    //   tap((e) => console.log('filtered ' + e))
    //   ).subscribe((i) => this.version = i);
    this.versionObservable = this.versionService.getObservable();
  }

  toggle(): void {
    this.open = !this.open;
  }

  callIncrementVersion() {
    this.versionService.incrementVersion();
  }
  callDecrementVersion() {
    this.versionService.decrementVersion();
  }

}
